import unittest
import stpp


class DistributionTests(unittest.TestCase):
    def setUp(self):
        self.chi2dist = stpp.ChiSquareDistribution()
        self.expdist = stpp.ExponentialDistribution()
        self.gammdist = stpp.GammaDistribution()
        self.norm = stpp.NormalDistribution()
        self.studentt = stpp.StudentTDistribution()
        self.unit_square = [
            0.001, 0.005, 0.010, 0.025, 0.050, 0.100, 0.250, 0.500, 0.750,
            0.900, 0.950, 0.975, 0.990, 0.995, 0.999
        ]

    def test_simulate(self):
        simulations_number = 9
        seed = 1234

        sims_chi = [
            1.3769707923868992000, 3.405722618451861000, 1.894076732953657000,
            2.9512124215427633000, 3.941816866247279400, 0.326537163669584630,
            0.4425874268921390400, 3.376561133495471300, 0.345888174208010200
        ]
        sims_exp = [
            0.6884853961934501000, 1.702861309225930000, 0.947038366476828800,
            1.4756062107713823000, 1.970908433123638600, 0.163268581834792120,
            0.2212937134460686000, 1.688280566747735400, 0.172944087104005130
        ]
        sims_gamma = [
            1.6709014233806272000, 3.118302332435075000, 2.068095317922449300,
            2.8143858900993157000, 3.467805862806017000, 0.685083990231682100,
            0.8202889847717110000, 3.099031226259925600, 0.708644387195065000
        ]
        sims_norm = [
            -0.005856353572075632, 0.907158257520544900, 0.284827617087289000,
            0.7433328929374164000, 1.083333427702759000, -1.03370534964237540,
            -0.846923935428695500, 0.897083932345440900, -0.99933857064858740
        ]
        sims_t = [
            -0.006230273566163069, 1.022562849459056000, 0.304719530592514170,
            0.8219405231043041000, 1.252372390840388000, -1.18595206458163820,
            -0.947496860155917000, 1.009894183443656600, -1.14076290586540900
        ]

        self.assertEqual(self.chi2dist.simulate(simulations_number, seed),
                         sims_chi,
                         msg=f"testing chi-square distribution simulation")
        self.assertEqual(self.expdist.simulate(simulations_number, seed),
                         sims_exp,
                         msg=f"testing exponential distribution simulation")
        self.assertEqual(self.gammdist.simulate(simulations_number, seed),
                         sims_gamma,
                         msg=f"testing gamma distribution simulation")
        self.assertEqual(self.norm.simulate(simulations_number, seed),
                         sims_norm,
                         msg=f"testing normal distribution simulation")
        self.assertEqual(self.studentt.simulate(simulations_number, seed),
                         sims_t,
                         msg=f"testing student-t distribution simulation")

    def test_ppf(self):
        sample_chi = [
            0.002001000667167574, 0.010025083647089872, 0.020100671707002250,
            0.050635615968580794, 0.102586588775100300, 0.210721031315653560,
            0.575364144903559800, 1.386294361119894300, 2.772588722239788700,
            4.605170185988072000, 5.991464547107967000, 7.377758908227861000,
            9.210340371976145000, 10.59663473309626600, 13.81551055796535400
        ]
        sample_gamma = [
            0.045402017769504255, 0.103494546748095220, 0.148554740253260320,
            0.242209278543967340, 0.355361510698664060, 0.531811608389610100,
            0.961278763114776800, 1.678346990016663700, 2.692634528889691000,
            3.889720169867429500, 4.743864518390583000, 5.571643390938895000,
            6.638352067993926000, 7.430129500280032000, 9.233413476451513000
        ]
        sample_t = [
            -7.17318221978239200, -4.60409487134981700, -3.74694738797919150,
            -2.77644510519782400, -2.13184678632666370, -1.53320627405894180,
            -0.74069708411268310, 0.000000000000000000, 0.740697084112683100,
            1.533206274058941800, 2.131846786326663700, 2.776445105197824000,
            3.746947387979191500, 4.604094871349817000, 7.173182219782392000
        ]
        for i, uniform in enumerate(self.unit_square):
            self.assertEqual(
                self.chi2dist.ppf(uniform),
                sample_chi[i],
                msg=f"testing chi-square distribution ppf for {uniform}")
            self.assertEqual(
                self.gammdist.ppf(uniform),
                sample_gamma[i],
                msg=f"testing gamma distribution ppf for {uniform}")
            self.assertEqual(
                self.studentt.ppf(uniform),
                sample_t[i],
                msg=f"testing student-t distribution ppf for {uniform}")


if __name__ == "__main__":
    unittest.main()
