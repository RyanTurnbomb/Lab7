#Lab7

Library for implementing the IR sensors using the ADC10 subsystem on the MSP430.


##Functions
- `void getLeft`
  - Takes readings on P1.3 coming from the left IR sensor 
    
- `void getRight`
  - Takes readings on P1.4 coming from the right IR sensor

- `void getCenter`
  - Takes readings on P1.5 coming from the center IR sensor

## Notes
- Clears the ENC bit before taking a sensor reading
  - `ADC10CTL0 &= ~ENC`
- Clears the INCHx bits before reading as well
  - `ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);`

### Documentation
Worked through some of the logic with Baron and @babelcher.
@babelcher helped me debug some of my code
