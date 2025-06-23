# Stable Tree Labelling

A tool to speed up distance queries on large and dynamic road networks, 
It consists of the following main files:

* road_network.h / road_network.cpp: core library
* util.h / util.cpp: library with additional tools

Additional files are:

* index.cpp: create an index file
* query.cpp: load index from a file and evaluate random queries
* update.cpp: update index to reflect graph changes

# Usage

To Compile the source in `src/`

    $ make

To construct index:

    $ ./index graph_file_name index_file_name

To query index:

    $ ./query index_file_name query_file_name

To update index:

    $ ./update graph_file_name index_file_name update_file_name update_type(d - for decrease/i - for increase)

`Sample/` folder provides a sample road network, a sample file containing query pairs and a sample file containing update pairs

# References

* Henning Koehler, Muhammad Farhan, and Qing Wang, **[Stable Tree Labelling for Accelerating Distance Queries on Dynamic Road Networks](https://arxiv.org/pdf/2501.17379)**. EDBT 2025.
