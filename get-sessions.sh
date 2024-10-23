if [ -f master2025.txt ]; then
    echo "master2024.txt found! Making a copy..."
	cp master2025.txt session-copies/master2025-"`date +"%d-%m-%Y"`".txt.copy
fi

if [ -f master2025-int.txt ]; then
    echo "master2024-int.txt found! Making a copy..."
	cp master2025-int.txt session-copies/master2025-int-"`date +"%d-%m%Y"`".txt.copy
fi

#curl --location --cookie cookies.txt https://cddis.nasa.gov/archive/vlbi/ivscontrol/master2024.txt > master2024.txt
#curl --location --cookie cookies.txt https://cddis.nasa.gov/archive/vlbi/ivscontrol/master2024-int.txt > master2024-int.txt
curl --location --cookie cookies.txt https://cddis.nasa.gov/archive/vlbi/ivscontrol/master2024.txt > master2025.txt
curl --location --cookie cookies.txt https://cddis.nasa.gov/archive/vlbi/ivscontrol/master2024-int.txt > master2025-int.txt

