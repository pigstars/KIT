#!/bin/bash
for i in {1..100}
do
	./mid_client  127.0.0.1 9999 &
done
