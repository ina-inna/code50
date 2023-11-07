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


-- retrieve Fiftyville airport id
SELECT id from airports
   ...> WHERE full_name LIKE '%Fiftyville%';
