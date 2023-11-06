SELECT DISTINCT name FROM people
   ...> JOIN stars ON people.id = stars.person_id
   ...> JOIN movies ON stars.person_id = movies.id
   ...> WHERE movies.id IN (
   ...> SELECT movie_id FROM stars
   ...> WHERE person_id = (SELECT id from people WHERE name = 'Kevin Bacon')
   ...> );