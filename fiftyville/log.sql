-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description FROM crime_scene_reports
   ...> WHERE year = 2021 AND month = 7 AND day = 28
   ...> AND street = 'Humphrey Street';

   -- check interview reports with bakery
SELECT transcript FROM interviews
   ...> WHERE year = 2021 AND month = 7 AND day = 28
   ...> AND transcript LIKE '%bakery%';

-- check license plate of the thief in the bakery security logs
SELECT license_plate from bakery_security_logs
   ...> WHERE year = 2021 AND month = 7 AND day = 28
   ...> AND hour = 10 AND minute >=15 AND minute <=25;

   -- list of suspects: retrieved license plates
   SELECT name FROM people
   ...> WHERE license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55');

   -- list of suspects from ATM transactions by account number:
   SELECT account_number, transaction_type from atm_transactions
   ...> WHERE year = 2021 AND month = 7 AND day = 28
   ...> AND atm_location LIKE '%Leggett%';

   -- narrow down the list of witnesses by finding those who are in both lists: license plates and account numbers:
   SELECT people.name, people.passport_number FROM people
   ...> JOIN bank_accounts ON people.id = bank_accounts.person_id
   ...> WHERE people.license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55')
   ...> AND bank_accounts.account_number IN (28500762, 28296815, 76054385, 49610011, 16153065, 25506511, 81061156, 26013199);


-- retrieve those who are flying early from Fiftyville with the passport numbers of suspects: Bruce and Luca
   SELECT people.name, flights.hour, flights.minute FROM people
   ...> JOIN passengers ON people.passport_number = passengers.passport_number
   ...> JOIN flights ON passengers.flight_id = flights.id
   ...> WHERE flights.origin_airport_id IN
   (SELECT airports.id FROM airports
   WHERE full_name LIKE '%Fiftyville%'
   )
   ...> AND flights.year = 2021 AND flights.month = 7 AND flights.day = 29
   ...> AND people.passport_number IN (5773159633, 3592750733, 7049073643, 8496433585);


   -- retrive Luca and Bruce's phone numbers
   SELECT phone_number FROM people
   ...> WHERE passport_number IN (5773159633, 8496433585);



-- find out the phone number of the thief caller and who booked tickets:

SELECT caller, receiver FROM phone_calls
   ...> WHERE year = 2021 AND month = 7 AND day = 28
   ...> AND duration <=60
   ...> AND caller IN ('(389) 555-5198', '(367) 555-5533');

   -- find out names of the caller and receiver: Bruce and Robin
   SELECT name FROM people
   ...> WHERE phone_number IN ('(367) 555-5533', '(375) 555-8161');


   -- desitnation airport ID
   SELECT fli FROM flights
   ...> JOIN passengers ON flights.id = passengers.flight_id
   ...> WHERE origin_airport_id = 8
   ...> AND flights.year = 2021 AND flights.month = 7 AND flights.day = 29
   ...> AND passengers.passport_number = 5773159633;