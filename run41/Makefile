run:
	../gem/build/X86/gem5.fast ../system/system_6cpu_o3_4G.py --binary ../code/l2_mshr_measurement

clean:
	rm -rf m5out*

grep:
	grep -r -e "Begin" -e "End" -e "maxMshrOccupancy" -e "maxROBOccupancy" ./m5out

time: 
	grep -r -e "simTicks" ./m5out
