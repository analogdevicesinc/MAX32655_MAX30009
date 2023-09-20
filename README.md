## Description

This project records galvanic skin response (GSR) or electrodermal activity (EDA) using the MAX30009 with the MAX32655 microcontroller.


The values for I-Phase, Q-Phase, BIOZ and adjusted BIOZ are printed to a file that can then be analysed or plotted

## Software

### Project Usage

- As is, when run, the program will wait 100 counts and then print the Quadrature Phase, In Phase, BIOZ and adjusted BIOZ in four separate columns as below:
  
|Quad Phase|In Phase|BIOZ|Adjusted BIOZ| 
|-----|-----|-----|-----|
|12291.000000|      9556.000000|      51515.124947|      46353.879949|
|12290.000000|      9560.000000|      51520.638092|      46359.450341|
|12295.000000|      9555.000000|      51523.544096|      46362.386522|
|12293.000000|      9552.000000|      51512.227608|     46350.952527|
|12291.000000|     9556.000000 |     51515.124947|      46353.879949|
|12296.000000|      9549.000000|      51513.977253|      46352.720338|
|12294.000000|      9556.000000|      51522.962058|      46361.798440|
|12300.000000|      9559.000000|      51544.729169|      46383.791646|
|12302.000000|      9555.000000|      51541.834769|      46380.867176|
|12302.000000|      9555.000000|      51541.834769|      46380.867176|
|12290.000000|      9556.000000|      51512.512737|      46351.240616|
|12291.000000|      9551.000000|      51504.971749|      46343.621338|
|12294.000000|      9551.000000|      51512.810405|      46351.541374|
|12296.000000|      9554.000000|      51524.126552|      46362.975027|
|12293.000000|      9551.000000|      51510.197439|     46348.901280|
|12294.000000|      9554.000000|      51518.900999|      46357.695210|
|12291.000000|      9555.000000|      51513.094043|      46351.827957|
|12287.000000|      9550.000000|      51492.490675|      46331.010712|
|12293.000000|      9555.000000|      51518.318909|      46357.107075|
|12298.000000|      9556.000000|      51533.412660|      46372.357580|
|12299.000000|      9554.000000|      51531.965481|      46370.895369|
|12294.000000|      9555.000000|     51520.931462|      46359.746757|
|12286.000000|      9552.000000|      51493.939813|      46332.474891|

- These must also be printed to a separate .txt file that can be done by turning on the Toggle File Logging and choosing a Log File Directory:
![VSCode Log File](./images/Logging.png "VSCode Logging")

### Project-Specific Build Notes
-	Visual Studio Code that is capable of writing/compiling C programs.
-	MATLAB or Excel to plot outputs.




## Setup


### Hardware needed
 - Connect the MAX32655FTHR to the MAX30009EVKIT via SPI lines
 - Connect jumpers J5 and J7, leaving J4, J6, J7 and J8 open
 - Replace the capacitors C5, C6, C7 and C8 with capacitors of at least 220nF
 - Use two wet or dry electrodes on the wrist, connected 4cm apart
