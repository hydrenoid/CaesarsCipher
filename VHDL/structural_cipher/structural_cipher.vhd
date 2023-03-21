LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY full_adder IS
	PORT(x : in STD_LOGIC;
		  y : in STD_LOGIC;
		  cin : in STD_LOGIC;
		  sum : out STD_LOGIC;
		  cout : out STD_LOGIC);
END full_adder;

ARCHITECTURE behavior OF full_adder IS
BEGIN
	sum <= (x xor y) xor cin;
	cout <= (x and (y or cin)) or (cin and y);
END behavior;

LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY structural_cipher IS 
	PORT(a : in STD_LOGIC_VECTOR(7 downto 0);
		  b : in STD_LOGIC_VECTOR(3 downto 0);
		  d : in STD_LOGIC;
		  sum : out STD_LOGIC_VECTOR(7 downto 0);
		  cout : out STD_LOGIC);
END structural_cipher;

ARCHITECTURE behavior OF structural_cipher IS
COMPONENT full_adder IS
	PORT(x : in STD_LOGIC;
		  y : in STD_LOGIC;
		  cin : in STD_LOGIC;
		  sum : out STD_LOGIC;
		  cout : out STD_LOGIC);
END COMPONENT;
SIGNAL c1, c2, c3, c4, c5, c6, c7, c8: STD_LOGIC;
BEGIN
	FA0 : full_adder port map(a(0), d xor b(0), d, sum(0), c1);
	FA1 : full_adder port map(a(1), d xor b(1), c1, sum(1), c2);
	FA2 : full_adder port map(a(2), d xor b(2), c2, sum(2), c3);
	FA3 : full_adder port map(a(3), d xor b(3), c3, sum(3), c4);
	FA4 : full_adder port map(a(4), d xor '0', c4, sum(4), c5);
	FA5 : full_adder port map(a(5), d xor '0', c5, sum(5), c6);
	FA6 : full_adder port map(a(6), d xor '0', c6, sum(6), c7);
	FA7 : full_adder port map(a(7), d xor '0', c7, sum(7), c8);
	cout <= c5;
END behavior;