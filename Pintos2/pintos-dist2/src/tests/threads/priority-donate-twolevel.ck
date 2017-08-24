# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(priority-donate-twolevel) begin
(priority-donate-twolevel) Thread C finished.
(priority-donate-twolevel) Thread D finished.
(priority-donate-twolevel) Thread B finished.
(priority-donate-twolevel) Thread A finished.
(priority-donate-twolevel) end
EOF
pass;