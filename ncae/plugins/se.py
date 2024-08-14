from ncae.audio import Audio


class NCAEPluginSE:

    def __init__(self, data: dict):

        self.ambience = data["ambience"]
        self.presence = data["presence"]
        self.sshaper = data["sshaper"]
        self.stereoizer = data["stereoizer"]

    def applyto(self, audio: Audio):

        raise NotImplementedError
