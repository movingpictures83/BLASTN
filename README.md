# BLASTN
# Language: C++
# Input: TXT
# Output: TXT
# Tested with: PluMA 1.0, GCC 4.8.4
# Dependency: BLAST 2.2.25

PluMA plugin to BLAST a series of sequences (nucleotide format)
against a database. 

The plugin takes as input a parameter file of tab-delimited keyword-value
pairs:

query	FASTA file
db	Database file
outfmt	Output file format

Alignment will be returned in the specified outputfile.
