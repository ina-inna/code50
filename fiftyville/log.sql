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


