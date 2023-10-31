import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    new_cases = {}
    data = list(reader)
    previous_cases = {}

    for row in reversed(data):
        state = row['state']
        cases = row['cases']
        if state not in previous_cases:
            previous_cases[state] = []
        previous_cases[state].append(cases)

        if len(previous_cases[state]) > 15:
            previous_cases[state].pop()
        for state, cases_list in previous_cases.items():
                new_cases[state] = [cases.list[i] - cases.list[i+1] for i in range (14)]



    return new_cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    return


main()
