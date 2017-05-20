#include <LA.h>
#include <parser.h>

int main(int argc, char **argv) {
  bool verbose;

  /* Check the input */
  if( argc < 2 ) {
  std::cerr << "Usage: " << argv[ 0 ] << " SOURCE [-v]" << std::endl;
    return 1;
  }
  int32_t opt;
  while ((opt = getopt(argc, argv, "v")) != -1) {
    switch (opt) {
      case 'v':
        verbose = true;
        break;

      default:
        std::cerr << "Usage: " << argv[ 0 ] << "[-v] SOURCE" << std::endl;
        return 1;
    }
  }

  std::ofstream outputFile;
  outputFile.open("prog.L3");

  // LA::Tile * t = new LA::Tile();

  LA::Program p = LA::LA_parse_file(argv[optind]);

  // outputFile << "(:main\n";

  for (auto f : p.functions) {
    outputFile << "define " << f->name << " ( ";
    if (f->arguments.size() > 0) {
      outputFile << f->arguments[0]->toString();
    }

    for (int k = 1; k < f->arguments.size(); k++) {
      outputFile << ", " << f->arguments[k]->toString();
    }

    outputFile << " ) {";

    for (auto bb : f->bbs) {
      outputFile << "\n\t" << bb->label;
      for (auto ins : bb->inss) {
        ins->toL3(outputFile, f);
        // outputFile << "\n\t" << ins->toString();
      }
      bb->te->toL3(outputFile, f);
    }

    outputFile << "\n}\n";
  }

  outputFile.close();

  std::cout << "yeahhhhh\n";
  // LA::debug("yeahhhhh");
}
