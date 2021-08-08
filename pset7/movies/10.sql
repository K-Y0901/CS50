SELECT people.name FROM people JOIN directors ON people.id = directors.person_id JOIN movies ON directors.movie_id JOIN ratings ON directors.movie_id = ratings.movie_id WHERE raitngs.rating >= 9.0;