setup: build-boot

build-boot:
	docker exec -it tacos /usr/bin/make -C app/aarch/rasp4/boot clean
	docker exec -it tacos /usr/bin/make -C app/aarch/rasp4/boot

enter:
	docker exec -it --workdir /app tacos bash

start:
	docker-sync-stack start

generate-config:
	docker exec --workdir /generator tacos_sbt sbt "run --filename=$(file)"
	
test-config:
	docker exec -it --workdir /app/src tacos aarch64-elf-c++ --std=c++17 -c kernel/config.cpp -I types/ -I libuser/apex/ -I apex/

docs:
	docker exec -it --workdir /data tacos_doxygen doxygen .doxygen