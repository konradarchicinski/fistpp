import unittest
import fistpp as fs


class MersenneTwisterTests(unittest.TestCase):
    def setUp(self):
        self.uniforms = [
            0.99718480823026560, 0.93255736136816550, 0.12812444777230600,
            0.99904051546527360, 0.23608897629816922, 0.39658072616260930,
            0.38791074026056105, 0.66974604044704710, 0.93553907270468020,
            0.84631091834484060, 0.31327351308874657, 0.52454816286573640
        ]

    def test_random_uniform(self):
        mt = fs.MersenneTwister(lower_bound=0.0, upper_bound=1.0, seed=1)

        for i, uniform in enumerate(self.uniforms):
            self.assertEqual(mt.random_uniform(),
                             uniform,
                             msg=f"testing uniform {i+1}/{len(self.uniforms)}")


if __name__ == "__main__":
    unittest.main()