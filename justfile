setup TARGET:
	rm -rf target/{{TARGET}}
	mkdir target/{{TARGET}}/examples -p

# build TARGET: (setup TARGET)
# 	gcc lib.c -c -o target/{{TARGET}}/lib.o
# 	cd target/{{TARGET}} && ar rcs lib.a lib.o

run TARGET EXAMPLE: (setup TARGET)
	@echo "Compiling Example {{EXAMPLE}}:"
	gcc examples/{{EXAMPLE}}.c -o target/{{TARGET}}/examples/{{EXAMPLE}} -fuse-ld=mold
	@echo ""
	target/{{TARGET}}/examples/{{EXAMPLE}}
