# Signal processing simulation
## Description
The goal of the task is to write a program to simulate signal processing using sample-after-sample method according to given block diagram.
Program should be tested using block diagram for modelling FM demodulation of quadrature sampled radio signal recorded in file:
<p align="center"><img src="diagram1.png" /></p>

## Blocks functionality
- cu8data - reads complex number samples from recorded file
- fmshift - shifts signal spectrum to the frequency of used station
- decimate - averages the last p samples on-spot, returns average value for every p samples cluster
- fmdemod - performs FM demodulation
- au - saves samples to .au file

## Example
#### Input: fm1_99M726_1M92.cu8
#### Output: output.au
