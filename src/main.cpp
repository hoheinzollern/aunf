#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

#include "readpep.h"
#include "unf.h"

using namespace std;

void usage() {
    cerr <<
"Usage: aunf [parameters] file_name\n\n"
"Parameters:\n"
"        -dot         Dot output (default)\n"
"        -ll          LLnet output\n"
"        -asp         Answer Set Programming output\n"
"        -convert     No net unfolding, just output the original net\n"
"        -histinf     Include history information\n"
"                     (only applies to ll nets with applied unfolding)\n"
"        -o file_name Output to file\n";
}

#define OUTPUT_FORMAT_DOT   0
#define OUTPUT_FORMAT_LLNET 1
#define OUTPUT_FORMAT_ASP   2

template <class T> void output(char *output_file, T *net, int format) {
    ostream *out = output_file == 0? &cout : new ofstream(output_file);
    if (format == OUTPUT_FORMAT_DOT) {
        writeDot(*out, net);
    } else if (format == OUTPUT_FORMAT_LLNET) {
        writeLL(*out, net);
    } else if (format == OUTPUT_FORMAT_ASP) {
        writeAsp(*out, net);
    }
}

int main(int argc, char** argv) {
  cerr << "AUnf - Unfolder for Contextual Petri Nets" << endl;
  if (argc < 2)
      usage();
  else {
      char *input_file = 0;
      char *output_file = 0;
      int output_format = OUTPUT_FORMAT_DOT;
      bool convert = false;
      bool histinf = false;

      for (int i = 1; i < argc; i++) {
          if (strcmp(argv[i], "-dot") == 0)
              output_format = OUTPUT_FORMAT_DOT;
          else if (strcmp(argv[i], "-ll") == 0)
              output_format = OUTPUT_FORMAT_LLNET;
          else if (strcmp(argv[i], "-asp") == 0)
              output_format = OUTPUT_FORMAT_ASP;
          else if (strcmp(argv[i], "-convert") == 0)
              convert = true;
          else if (strcmp(argv[i], "-histinf") == 0)
              histinf = true;
          else if (strcmp(argv[i], "-o") == 0) {
              i++;
              if (i < argc)
                  output_file = argv[i];
              else {
                  cerr << "output file not specified!\n";
                  exit(1);
              }
          }
          else if (argv[i][0] == '-') {
              cerr << "option not recognized!\n";
              exit(1);
          } else
              input_file = argv[i];
      }
      if (input_file == 0) {
          cerr << "input file not specified!\n";
          exit(1);
      }
      Net *net = read_pep_net(input_file);
      cerr << "Read " << input_file << ": " << net->places.size() << " places and "
           << net->transitions.size() << " transitions parsed" << endl;
      if (!convert) {
        Unfolder *unf = new Unfolder();
        unf->net = net;

      } else {

      }
  }
  return 0;
}
