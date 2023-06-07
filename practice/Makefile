default: pre
pre: $(file)
	g++ $(file)
	./a.out
# using the -f option with rm prevents the target from failing if the specified files are not present. 
# It ensures that the clean-up process continues without interruption, regardless of whether the files to be removed exist or not.
clean:
	rm -f a.out
	rm -f *.bin
	

