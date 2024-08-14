from ncae.audio import Audio


class NCAEPluginEQ:

    def __init__(self, data: dict):

        assert len(data["eqs"]) == 10
        self.eqs = data["eqs"]

    def applyto(self, audio: Audio):

        raise NotImplementedError
