# count_unique_reads
C++ program to take a FASTQ file and count the unique sequences. Could be useful for counting single indexes or counting detected amplicons from amplicon-seq. More for QC than analysis. Relatively speedy.

## Installation
Requires Makefile and a g++ compiler capable of using the C++11 standard.

```bash
make
```

This will compile the count_unique_reads program, which can be copied to your user path for standard usage.

## Example usage
Standard FASTQ files, minimum 1000 reads to print a pair, print to standard out.
```bash
count_unique_reads --fastq myfile.fastq --threshold 1000
```

Standard FASTQ files, minimum 1000 reads to print a pair, print to file.
```bash
count_unique_reads --fastq myfile.fastq --threshold 1000 1>counts.tsv 2>errors.log
```

Bash environment, gzip FASTQ files (use process substitution), minimum 100,000 reads to print a pair, print to file. Run with no-hangup and in the background.
```bash
nohup count_unique_reads --fastq <(gunzip -cd myfile.fastq.gz) --threshold 100000 1>counts.tsv 2>errors.log &
```
