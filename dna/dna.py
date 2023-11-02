import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py database sequence")

    # TODO: Read database file into a variable
    database = {}
    with open(sys.argv[1]) as file:
        file_reader = csv.DictReader(file)
        # Store each name as a dictionary
        for row in file_reader:
            name = row["name"]

            if name not in database:
                database[name] = {}

            sequences = {}
            for column_name in row.keys():
                if column_name != 'name':
                    column_values = row[column_name].split(',') if row[column_name] else []
                    number_sequences = []
                    for value in column_values:
                        if value:
                            number_sequences.append(int(value))
                    database[name][column_name] = number_sequences
        print(database)


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
