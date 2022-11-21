# Error codes
### How they work
If an error occurs and there is proper handling setup for that error, text (which is defined in the cpp/messages.hpp file) will popup on the screen. 
Error codes do not say what happened in plain text, instead simply using the format `FAULT: <PRIORITY> <ERROR CODE>`
### List of Error codes by type
#### Generic
`FAULT: CRITICAL 000`: Unknown fault
#### Memory related
`FAULT: CRITICAL 100`: Out of memory<br>
`FAULT: CRITICAL 101`: Stack underflow<br>
`FAULT: CRITICAL 102`: Stack overflow<br>
`FAULT: CRITICAL 103`: Memory over-allocated<br>
`FAULT: CRITICAL 104`: Could not load file correctly when compiling<br>
#### Command line related
`FAULT: WARNING 200`: Unrecognized command
