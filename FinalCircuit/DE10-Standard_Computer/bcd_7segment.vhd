library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity bcd_7segment is
    port(
        input_bin: in std_logic_vector(3 downto 0);
        seg1: out std_logic_vector(6 downto 0);
        seg2: out std_logic_vector(6 downto 0)
    );
end entity;

architecture behavioral of bcd_7segment is

    signal input_dec: integer range 0 to 15;

begin

    input_dec <= to_integer(unsigned(input_bin));

    process(input_dec)
    begin
        case input_dec is
            when 0 =>  
                seg1 <= "1000000";
                seg2 <= "1000000";
            when 1 =>
                seg1 <= "1111001";
                seg2 <= "1000000";
            when 2 =>
                seg1 <= "0100100";
                seg2 <= "1000000";
            when 3 =>
                seg1 <= "0110000";
                seg2 <= "1000000";
            when 4 =>
                seg1 <= "0011001";
                seg2 <= "1000000";
            when 5 =>
                seg1 <= "0010010";
                seg2 <= "1000000";
            when 6 =>
                seg1 <= "0000010";
                seg2 <= "1000000";
            when 7 =>
                seg1 <= "1111000";
                seg2 <= "1000000";
            when 8 =>
                seg1 <= "0000000";
                seg2 <= "1000000";
            when 9 =>
                seg1 <= "0010000";
                seg2 <= "1000000";
            when 10 =>
                seg1 <= "1000000";
                seg2 <= "1111001";
            when 11 =>
                seg1 <= "1111001";
                seg2 <= "1111001";
            when 12 =>
                seg1 <= "0100100";
                seg2 <= "1111001";
            when 13 =>
                seg1 <= "0110000";
                seg2 <= "1111001";
            when 14 =>
                seg1 <= "0011001";
                seg2 <= "1111001";
            when 15 =>
                seg1 <= "0010010";
                seg2 <= "1111001";
            when others =>
                seg1 <= "1111111";
                seg2 <= "1111111";
        end case;
    end process;

end architecture;
