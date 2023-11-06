SELECT DISTINCT name FROM people JOIN stars on people.id=person_id
JOIN movies ON movie_id=movies.id WHERE year = 2004 ORDER BY birth;
