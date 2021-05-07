import unittest
import stpp


class StudentTDistributionTests(unittest.TestCase):
    def setUp(self):
        self.studentt = stpp.StudentTDistribution()
        self.expected_values = [
            -7.17318221978239200, -4.60409487134981700, -3.74694738797919150,
            -2.77644510519782400, -2.13184678632666370, -1.53320627405894180,
            -0.74069708411268310, 0.000000000000000000, 0.740697084112683100,
            1.533206274058941800, 2.131846786326663700, 2.776445105197824000,
            3.746947387979191500, 4.604094871349817000, 7.173182219782392000
        ]
        self.expected_mass = [
            0.000524008602071603, 0.003765125375196593, 0.008681866447469551,
            0.025580817826673380, 0.056225096733004980, 0.118065654743593900,
            0.271943823596585530, 0.375000000000000060, 0.271943823596585530,
            0.118065654743593900, 0.056225096733004980, 0.025580817826673380,
            0.008681866447469551, 0.003765125375196593, 0.000524008602071603
        ]
        self.expected_probability = [
            0.001, 0.005, 0.010, 0.025, 0.050, 0.100, 0.250, 0.500, 0.750,
            0.900, 0.950, 0.975, 0.990, 0.995, 0.999
        ]

    def test_pdf(self):
        for i, x in enumerate(self.expected_values):
            self.assertAlmostEqual(self.studentt.pdf(x),
                                   self.expected_mass[i],
                                   msg=f"testing pdf for {x}")

    def test_cdf(self):
        for i, x in enumerate(self.expected_values):
            self.assertAlmostEqual(self.studentt.cdf(x),
                                   self.expected_probability[i],
                                   msg=f"testing cdf for {x}")

    def test_mean(self):
        self.assertEqual(self.studentt.mean(), 0.0)

    def test_variance(self):
        self.assertEqual(self.studentt.variance(), 2.0)


if __name__ == "__main__":
    unittest.main()