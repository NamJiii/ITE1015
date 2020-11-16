ALL: radix_notation draw_points prime_factorization reply_admin

radix_notation: radix_notation.o
	g++ -o radix_notation radix_notation.o

radix_notation.o: radix_notation.cc
	g++ -c radix_notation.cc

draw_points: draw_points.o
	g++ -o draw_points draw_points.o

draw_points.o: draw_points.cc
	g++ -c draw_points.cc

prime_factiorization: primfactorization.o
	g++ -o prime_factorization prime_factorization.o

prime_factoriaztion.o : prime_factorization.cc
	g++ -c prime_factorization.cc

reply_admin: reply_admin.o
	g++ -o reply_admin reply_admin.o

reply_admin.o: reply_admin.cc
	g++ -c reply_admin.cc

clean:
	rn draw_points
	rm radix_notation
	rm prime_factorization
	rm reply_admin
