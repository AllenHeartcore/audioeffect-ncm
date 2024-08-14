from ncae.audio import Audio


class NCAEPluginReverb:

    def __init__(self, data: dict):

        self.er = data["er"]
        self.il = data["il"]
        self.ol = data["ol"]
        self.rl = data["rl"]
        self.rvb = data["rvb"]
        self.tc = data["tc"]

    def applyto(self, audio: Audio):

        raise NotImplementedError
