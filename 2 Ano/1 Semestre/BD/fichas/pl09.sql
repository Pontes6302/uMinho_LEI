-- 18 
SELECT SUM(amount) * 0.125 AS lucro_2005 FROM payment WHERE YEAR (payment_date) = 2005;

-- 22
SELECT CONCAT(first_name, ' ', last_name) as nome, email, 'CUSTOMER' AS person_type 
FROM customer
UNION
SELECT CONCAT(first_name, ' ', last_name) as nome, email, 'STAFF' AS person_type 
FROM staff
ORDER BY nome;

-- 13
CREATE VIEW vw_customer_emails as 
SELECT customer_id, 
		CONCAT(first_name, ' ', last_name) as full_name, 
        email
FROM customer
ORDER BY customer_id;

-- 30
CREATE VIEW vw_last_films_actors AS
SELECT DISTINCT a.actor_id, a.first_name, a.last_name
FROM(
	SELECT i.film_id, MAX(rental_date) AS last_rental_date
	FROM rental r
	JOIN inventory i ON r.iventory_id = i.inventory_id
	GROUP BY film_id
	ORDER BY last_rental_date DESC
	LIMIT 10
) AS last_films
JOIN film_actor fa ON fa.film_id = last_films.film_id
JOIN actor a ON a.actor_id = fa.actor_id
ORDER BY a.last_name, a.first_name;
