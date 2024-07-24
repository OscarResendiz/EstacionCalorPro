EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_ST_STM32F1:STM32F103C8Tx U?
U 1 1 66A04699
P 4400 2900
F 0 "U?" H 4350 1311 50  0000 C CNN
F 1 "STM32F103C8Tx" H 4350 1220 50  0000 C CNN
F 2 "Package_QFP:LQFP-48_7x7mm_P0.5mm" H 3800 1500 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00161566.pdf" H 4400 2900 50  0001 C CNN
	1    4400 2900
	1    0    0    -1  
$EndComp
$Comp
L Sensor_Temperature:MAX6654 U?
U 1 1 66A058F4
P 7350 2850
F 0 "U?" H 7350 3531 50  0000 C CNN
F 1 "MAX6654" H 7350 3440 50  0000 C CNN
F 2 "Package_SO:SSOP-16_3.9x4.9mm_P0.635mm" H 7400 2250 50  0001 C CIN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX6654.pdf" H 7250 2850 50  0001 C CNN
	1    7350 2850
	1    0    0    -1  
$EndComp
$EndSCHEMATC
