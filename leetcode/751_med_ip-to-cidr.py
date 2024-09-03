class Solution(object):
    def ip_to_bin(self, ip):
        return "".join(["{:08b}".format(int(i)) for i in  ip.split(".") ])

    def bin_to_ip(self, bin):
        return ".".join([str(int(bin[i:i+8],2)) for i in range(0, 32, 8)])

    def ipToCIDR(self, ip, n):
        """
        :type ip: str
        :type n: int
        :rtype: List[str]
        """
        current_ip = self.ip_to_bin(ip)
        result = []
        while n > 0:
            last_one = 31
            while last_one > -1 and current_ip[last_one] is '0':
                last_one -= 1
            trailing_zeros = 31 - last_one

            while 2**trailing_zeros > n:
                trailing_zeros -= 1
            new_ip = self.bin_to_ip(current_ip)
            result.append(self.bin_to_ip(current_ip) + "/" + str(32 - trailing_zeros))
            num_in_range = 2 ** trailing_zeros
            n -= num_in_range
            current_ip = "{:032b}".format(int(current_ip, 2) + num_in_range)
        return result