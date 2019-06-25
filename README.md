# filteroverflow-framework

Framework to check for overflow conditions in fixed-point digital filters. Filters are in *filters* directory.

## Rationale

Digital filter design tools use floating-point arithmetic to calculate the filter parameters. However, due to hardware and processing restrictions, the implementation of digital filters in embedded systems often uses fixed-point arithmetic, which can compromise the algorithm robustness, leading to undesired effects such as instabilities and overflow conditions. In general, filter verification is done by extensive testing, but the overflow conditions resulted from the parameters quantization are extremely difficult to exercise during the tests. We propose a novel test generation approach for detecting overflow conditions in fixed-point digital filter realizations where the search for error states is modeled as an optimization problem and the input vector values are iteratively refined to trigger the overflow conditions, if they exist. We use our method to check several digital filters with different design parameters and bit widths and compare the obtained results against the largely adopted Random Testing and the computationally efficient Bounded Model Checking (BMC). Experiments show that, besides less restricted than BMC, the proposed algorithm can uncover overflow conditions in fixed-point digital filters faster than both alternatives.

## Usage

To check the filters using bounded model checking, go to the bmc directory and execute `make`.

To check the filters using the framework, goto to the *framework* directory, execute `make` and then run the executable of the filter.

