all:	build \
		run \
		clean \

build:	build_hello

run:	run_hello \
		run_exmaple1 \
		run_variable_constant \
		run_data_type \
		run_cond \
		run_loop \
		run_fn \
		run_fn_param_refer \
		run_fn_param_val \
		run_fn_as_param \
		run_fn_as_param_callback \
		run_fn_closure \
		run_fn_method \
		run_arr \
		run_fn_param_arr \
		run_multi_dimension_arr \
		run_pointer_arr \
		run_pointer_to_pointer \
		run_fn_ptr_param

clean:
	rm *.out

# ##########
build_hello:
	go build -o hello.out hello.go
	./hello.out

run_hello:
	go run hello.go

run_exmaple1:
	go run exmaple1.go

run_variable_constant:
	go run variable_constant.go

run_data_type:
	go run data_type.go

run_cond:
	go run cond.go

run_loop:
	go run loop.go

run_fn:
	go run fn.go

run_fn_param_refer:
	go run fn_param_refer.go

run_fn_param_val:
	go run fn_param_val.go

run_fn_as_param:
	go run fn_as_param.go

run_fn_as_param_callback:
	go run fn_as_param_callback.go

run_fn_closure:
	go run fn_closure.go

run_fn_method:
	go run fn_method.go

run_arr:
	go run arr.go

run_fn_param_arr:
	go run fn_param_arr.go

run_multi_dimension_arr:
	go run multi_dimension_arr.go

run_pointer_arr:
	go run pointer_arr.go

run_pointer_to_pointer:
	go run pointer_to_pointer.go

run_fn_ptr_param:
	go run fn_ptr_param.go
