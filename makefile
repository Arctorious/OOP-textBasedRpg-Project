test: Actor.cpp Player.cpp Monster.cpp Game.cpp Inventory.cpp main1.cpp
	g++ Actor.cpp Player.cpp Monster.cpp Game.cpp Inventory.cpp main1.cpp -o test

Battle_test: Actor.cpp Player.cpp Monster.cpp main3.cpp
	g++ Actor.cpp Player.cpp Monster.cpp main3.cpp -o test
test1: Actor.cpp main1.cpp
	g++ Actor.cpp main1.cpp -o test1
test2: Actor.cpp Player.cpp main1.cpp
	g++ Actor.cpp Player.cpp -o test2
test3: Actor.cpp Monster.cpp main1.cpp
	g++ Actor.cpp Monster.cpp -o test3
test4: Actor.cpp Monster.cpp Game.cpp
	g++ Actor.cpp Monster.cpp Game.cpp -o test4
test5: Actor.cpp Player.cpp Game.cpp
	g++ Actor.cpp Player.cpp Game.cpp -o test4

inv: Actor.cpp Player.cpp Inventory.cpp inven_test.cpp
	g++ Actor.cpp Player.cpp Inventory.cpp inven_test.cpp -o inv
