sim:
	verilator --cc --exe --build --trace ./csrc/wallace_8x8_product.cpp ./vsrc/wallace_8x8_product.v
clean:
	rm -r ./obj_dir
