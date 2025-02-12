# ITS Conversion

Tool to convert between the following three formats for Integer Transition Systems:
* the [`koat` format](https://aprove.informatik.rwth-aachen.de/eval/IntegerComplexity-Journal/) that has been used in the TermComp-category *Complexity of Integer Transition Systems* until 2024
* the [`smt2` format](https://www.microsoft.com/en-us/research/wp-content/uploads/2016/02/SMTPushdownPrograms.pdf) that has been used in the TermComp-category *Termination of Integer Transition Systems* until 2024
* the [`ari` format](https://termination-portal.org/wiki/Term_Rewriting) that is used for ITSs since 2025

Run `its-conversion-static --help` for more information.

The transformation is far from complete. It's supposed to work on the examples from the [TPDB](https://github.com/TermCOMP/TPDB), version `f8460262`, and will probably fail / yield incorrect results for other examples.
