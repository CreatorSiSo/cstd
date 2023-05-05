setup TARGET:
	rm -rf target/{{TARGET}}
	mkdir target/{{TARGET}}/examples -p

# build TARGET: (setup TARGET)
# 	gcc lib.c -c -o target/{{TARGET}}/lib.o
# 	cd target/{{TARGET}} && ar rcs lib.a lib.o

build TARGET EXAMPLE: (setup TARGET)
	@echo "Compiling Example {{EXAMPLE}}:"
	gcc examples/{{EXAMPLE}}.c -o target/{{TARGET}}/examples/{{EXAMPLE}} -fuse-ld=mold -Wall -g

run TARGET EXAMPLE: (build TARGET EXAMPLE)
	target/{{TARGET}}/examples/{{EXAMPLE}}

valgrind EXAMPLE: (build "debug" EXAMPLE)
	valgrind --leak-check=full -s target/debug/examples/{{EXAMPLE}}
