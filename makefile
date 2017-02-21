HEADERS = Term.h Autocomplete.h
	#(Term.h Autocomplete.h)

OBJECTS = main.o Term.o Autocomplete.o
        #(main.cpp Term.cpp Autocomplete.cpp)

AutocompleteProgram: $(OBJECTS)
	g++ $^ -o AutocompleteProgram

%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -i main.o Term.o Autocomplete.o
