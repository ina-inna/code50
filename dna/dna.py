import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py database sequence")

    # TODO: Read database file into a variable
    database = {}
    DNA_names = []
    with open(sys.argv[1]) as file:
        file_reader = csv.DictReader(file)
        # Store each name as a dictionary
        for row in file_reader:
            name = row["name"]

            if name not in database:
                database[name] = {}

            for column_name in row.keys():
                if column_name != 'name':
                    column_values = row[column_name].split(',') if row[column_name] else []
                    number_sequences = []
                    for value in column_values:
                        if value:
                            number_sequences.append(int(value))
                    database[name][column_name] = number_sequences
        print(database)
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as file2:
        sequence_txt = file2.read()

    print(sequence_txt)

    # TODO: Find longest match of each STR in DNA sequence
    #DNA = ['AGATC', 'TTTTTTCT', 'AATG', 'TCTAG', 'GATA', 'TATC', 'GAAA', 'TCTG']
    DNA_names = list(database[name].keys())
    print(DNA_names)
    counts = {}
    n = len(DNA_names)
    for name in DNA_names in range (n):
        result = longest_match(sequence_txt, name)
        if name not in counts:
            counts[name] = []
            counts[name].append(result)
    print(counts)





    # TODO: Check database for matching profiles

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
