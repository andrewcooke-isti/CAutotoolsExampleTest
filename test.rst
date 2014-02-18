
Example Tests
-------------

These are example tests, using the `Robot Framework
<http://robotframework.org>`_.

Before we run the tests we must load the required libraries.

=========  ===============
 Setting       Value
=========  ===============
Library    OperatingSystem
=========  ===============

For the first test, make sure that a sensible value is parsed
correctly:

===========  ===============  =================  ================
 Test Case       Action           Argument          Argument     
===========  ===============  =================  ================
Echo Value   [Documentation]  A valid value is 
                              read and echoed.
\            ${output} =      Run                src/main USD 10
\            Should Be Equal  ${output}          USD 10
===========  ===============  =================  ================

For the second, we expect an error:


===========  ===============  =================  ===================
 Test Case       Action           Argument          Argument     
===========  ===============  =================  ===================
Bad Value    [Documentation]  An invalid value
                              is rejected
\            ${output} =      Run                src/main USD 10X
\            Should Be Equal  ${output}          Could not parse 10X
===========  ===============  =================  ===================

