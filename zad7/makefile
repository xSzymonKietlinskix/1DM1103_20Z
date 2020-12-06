all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-add: all
	./mydb baza.csv add_student_to_course 1DE753 9210037

test-ile: all
	./mydb baza.csv count_students

test-memory: all
	valgrind ./mydb baza.csv count_students

clean:
	rm -f mydb
