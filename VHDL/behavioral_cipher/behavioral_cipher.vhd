library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity behavioral_cipher is
  port (
    a : in std_logic_vector(7 downto 0);
	 b : in std_logic_vector(3 downto 0);
    addsub : in std_logic;
    sum : out std_logic_vector(7 downto 0)
  );
end entity behavioral_cipher;

architecture behavioral of behavioral_cipher is
begin
  process(a, b, addsub)
  begin
    if addsub = '1' then
      sum <= std_logic_vector(unsigned(a) - unsigned(b));
    else
      sum <= std_logic_vector(unsigned(a) + unsigned(b));
    end if;
  end process;
end architecture behavioral;
