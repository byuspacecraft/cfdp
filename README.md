# cfdp
CCSDS File Delivery Protocol - Modifications to other sources to get it working for us.
## Documentation ##
CFDP documents distributed by CCSDS are in /specification

## Sources ##
* cFE - core flight executive by NASA Goddard, full flight software ecosystem
  * CFDP is the CF application
* ION - Interplanetary Network Stack by NASA JPL
 * CFDP relies on ici, ltp, dgr, and bp packages in ION.
 * From main ION directory use <code> make cleancfdp </code> and <code> make cfdpreqs </code> to make the cfdp required files.
 * Makefiles for ici, ltp, dgr, bp and cfdp have been modified to use arm-uclinuxeabi-gcc as the compiler.
 * Man pages for all of the executables created during a build can be found in <code> [package (i.e. ici)]/doc/man/man#/ </code> and can be run by using <code> man -l [filename] </code>
