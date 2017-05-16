#include <IR.h>
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

  // IR::Tile * t = new IR::Tile();

  IR::Program p = IR::IR_parse_file(argv[optind]);

  // outputFile << "(:main\n";

  for (auto f : p.functions) {
    outputFile << "define " << f->name << " ( ";

    for (auto arg : f->arguments) {
      outputFile << arg->name << " ";
    }

    outputFile << " ) {";

    for (auto bb : f->bbs) {
      outputFile << "\n\t" << bb->label;
      for (auto ins : bb->inss) {
        outputFile << "\n\t" << ins->toString();
      }
      outputFile << "\n\t" << bb->te->toString();
    }

    outputFile << "\n}\n";
  }

  outputFile.close();

  std::cout << "yeahhhhh\n";
  // IR::debug("yeahhhhh");
}
