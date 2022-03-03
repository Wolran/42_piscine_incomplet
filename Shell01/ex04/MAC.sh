ifconfig -a | sed -n 's+.*ether \([^ ]*\).*+\1+p' 
