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
    # create 2 dictionaries to store data
    new_cases = {}
    previous_cases = {}

    data = list(reader)


    for row in reversed(data):
        state = row['state']
        cases = int(row['cases'])
        if state not in previous_cases:
            previous_cases[state] = []
        previous_cases[state].append(cases)

        if len(previous_cases[state]) > 15:
            previous_cases[state].pop()
    for state, cases_list in previous_cases.items():
        new_cases[state] = [cases_list[i] - cases_list[i+1] for i in range (14)]

    print(new_cases)
    return new_cases


# TODO: Calculate and print out seven day average for given statenew
def comparative_averages(new_cases, states):

    for state in states:
        last_week = 0
        previous_week = 0
        for cases in new_cases[state][:7]:
            last_week += cases
        for cases in new_cases[state][8:15]:
            previous_week += cases
        last_week /= 7
        last_week = int(last_week)
        previous_week /= 7
        previous_week = int(previous_week)

        if previous_week >= last_week:
            try:
                percent = int(previous_week / last_week)*100
                print(f'{state} had a 7 day average of {last_week} and a decrease of {percent}%.')
            except ZeroDivisionError:
                print("Error: Division by zero is not allowed.")
        elif previous_week < last_week:
            try:
                percent = int(previous_week / last_week)*100
                print(f'{state} had a 7 day average of {last_week} and a decrease of {percent}%.')
            except ZeroDivisionError:
                print("Error: Division by zero is not allowed.")


main()