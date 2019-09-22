cc -std=c99 -Wall hello_world.c -o hello_world
cc -std=c99 -Wall prompt.c -ledit -o prompt
cc -std=c99 -Wall doge_grammer.c mpc.c -ledit -lm -o doge_grammer
cc -g -std=c99 -Wall parsing.c mpc.c -ledit -lm -o parsing
cc -std=c99 -Wall parsing_ab.c mpc.c -ledit -lm -o parsing_ab
cc -std=c99 -Wall parsing_ab2.c mpc.c -ledit -lm -o parsing_ab2
