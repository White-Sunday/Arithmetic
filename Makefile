sim:
	verilator --cc --exe --build --trace ./csrc/cla32.cpp ./vsrc/cla32.v
clean:
	rm -r ./obj_dir
