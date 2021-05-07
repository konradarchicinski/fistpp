import unittest
import stpp


class NormalDistributionTests(unittest.TestCase):
    def setUp(self):
        self.norm = stpp.NormalDistribution()
        self.expected_values = [
            -3.09023230616781230, -2.57582930354889950, -2.32634787404084080,
            -1.95996398454005400, -1.64485362695147300, -1.28155156554460080,
            -0.67448975019608180, 0.000000000000000000, 0.674489750196081800,
            1.281551565544600800, 1.644853626951472400, 1.959963984540054000,
            2.326347874040840800, 2.575829303548899500, 3.090232306167812300
        ]
        self.expected_mass = [
            0.003367090077064005, 0.014459743026917453, 0.026652142203458080,
            0.058445069805035380, 0.103135640375371230, 0.175498331932486730,
            0.317776572684107000, 0.398942280401432700, 0.317776572684107000,
            0.175498331932486730, 0.103135640375371350, 0.058445069805035380,
            0.026652142203458080, 0.014459743026917453, 0.003367090077064005
        ]
        self.expected_probability = [
            0.001, 0.005, 0.010, 0.025, 0.050, 0.100, 0.250, 0.500, 0.750,
            0.900, 0.950, 0.975, 0.990, 0.995, 0.999
        ]

    def test_pdf(self):
        for i, x in enumerate(self.expected_values):
            self.assertAlmostEqual(self.norm.pdf(x),
                                   self.expected_mass[i],
                                   msg=f"testing pdf for {x}")

    def test_cdf(self):
        for i, x in enumerate(self.expected_values):
            self.assertAlmostEqual(self.norm.cdf(x),
                                   self.expected_probability[i],
                                   msg=f"testing cdf for {x}")

    def test_ppf(self):
        for i, p in enumerate(self.expected_probability):
            self.assertAlmostEqual(self.norm.ppf(p),
                                   self.expected_values[i],
                                   msg=f"testing ppf for {p}")

    def test_mean(self):
        self.assertEqual(self.norm.mean(), 0.0)

    def test_variance(self):
        self.assertEqual(self.norm.variance(), 1.0)


if __name__ == "__main__":
    unittest.main()