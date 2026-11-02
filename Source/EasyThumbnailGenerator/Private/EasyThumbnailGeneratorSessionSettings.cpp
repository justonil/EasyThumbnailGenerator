#include "EasyThumbnailGeneratorSessionSettings.h"

UEasyThumbnailGeneratorSessionSettings::UEasyThumbnailGeneratorSessionSettings()
{
    ApplyPreset(EEasyThumbnailGeneratorPreset::WeaponSide);
    Preset = EEasyThumbnailGeneratorPreset::WeaponSide;
    OutputResolution = 1024;
    FramePaddingPercent = 5.0f;
}

void UEasyThumbnailGeneratorSessionSettings::ApplyPreset(EEasyThumbnailGeneratorPreset InPreset)
{
    Preset = InPreset;

    if (InPreset != EEasyThumbnailGeneratorPreset::Custom)
    {
        FramingMode = EEasyThumbnailGeneratorFramingMode::VisibleContent;
        FrameOffset = FVector::ZeroVector;
        bShowBounds = false;
    }

    switch (InPreset)
    {
    case EEasyThumbnailGeneratorPreset::WeaponSide:
        ProjectionMode = EEasyThumbnailGeneratorProjectionMode::Perspective;
        CameraYaw = -90.0f;
        CameraPitch = 0.0f;
        PerspectiveFOV = 25.0f;
        DirectionalLightIntensity = 8.0f;
        DirectionalLightYaw = -35.0f;
        DirectionalLightPitch = -45.0f;
        SkyLightIntensity = 1.0f;
        bUseManualExposure = true;
        ExposureCompensation = 1.0f;
        break;

    case EEasyThumbnailGeneratorPreset::WeaponThreeQuarter:
        ProjectionMode = EEasyThumbnailGeneratorProjectionMode::Perspective;
        CameraYaw = -125.0f;
        CameraPitch = -8.0f;
        PerspectiveFOV = 25.0f;
        DirectionalLightIntensity = 8.0f;
        DirectionalLightYaw = -35.0f;
        DirectionalLightPitch = -45.0f;
        SkyLightIntensity = 1.0f;
        bUseManualExposure = true;
        ExposureCompensation = 1.0f;
        break;

    case EEasyThumbnailGeneratorPreset::AssetDefault:
        ProjectionMode = EEasyThumbnailGeneratorProjectionMode::Perspective;
        CameraYaw = -135.0f;
        CameraPitch = -15.0f;
        PerspectiveFOV = 30.0f;
        DirectionalLightIntensity = 7.0f;
        DirectionalLightYaw = -35.0f;
        DirectionalLightPitch = -45.0f;
        SkyLightIntensity = 1.0f;
        bUseManualExposure = true;
        ExposureCompensation = 1.0f;
        break;

    case EEasyThumbnailGeneratorPreset::Custom:
    default:
        break;
    }
}


void UEasyThumbnailGeneratorSessionSettings::ApplyRenderSettings(
    const FEasyThumbnailGeneratorRenderSettings& Settings,
    EEasyThumbnailGeneratorPreset InPreset)
{
    Preset = InPreset;
    OutputResolution = Settings.OutputResolution;
    GridWidth = Settings.GridWidth;
    GridHeight = Settings.GridHeight;
    FramePaddingPercent = Settings.FramePaddingPercent;
    FramingMode = Settings.FramingMode;
    FrameOffset = Settings.FrameOffset;
    bShowBounds = Settings.bShowBounds;
    bShowCheckerboard = Settings.bShowCheckerboard;
    bUsePreviewSceneSettings = Settings.bUsePreviewSceneSettings;
    bCaptureBloom = Settings.bCaptureBloom;
    bCaptureAntiAliasing = Settings.bCaptureAntiAliasing;
    bCaptureTemporalAA = Settings.bCaptureTemporalAA;
    bCaptureEveryFrame = Settings.bCaptureEveryFrame;
    bCaptureOnMovement = Settings.bCaptureOnMovement;
    bCaptureVignette = Settings.bCaptureVignette;
    bCaptureEyeAdaptation = Settings.bCaptureEyeAdaptation;
    bCapturePostProcessing = Settings.bCapturePostProcessing;
    bCaptureTonemapper = Settings.bCaptureTonemapper;
    bCaptureLighting = Settings.bCaptureLighting;
    bCaptureReflections = Settings.bCaptureReflections;
    bCaptureDeferredLighting = Settings.bCaptureDeferredLighting;
    bCaptureMaterials = Settings.bCaptureMaterials;
    bCaptureDepthOfField = Settings.bCaptureDepthOfField;
    ProjectionMode = Settings.ProjectionMode;
    CameraYaw = Settings.CameraYaw;
    CameraPitch = Settings.CameraPitch;
    PerspectiveFOV = Settings.PerspectiveFOV;
    DirectionalLightIntensity = Settings.DirectionalLightIntensity;
    DirectionalLightYaw = Settings.DirectionalLightYaw;
    DirectionalLightPitch = Settings.DirectionalLightPitch;
    SkyLightIntensity = Settings.SkyLightIntensity;
    bUseManualExposure = Settings.bUseManualExposure;
    ExposureCompensation = Settings.ExposureCompensation;
}

FEasyThumbnailGeneratorRenderSettings UEasyThumbnailGeneratorSessionSettings::MakeRenderSettings() const
{
    FEasyThumbnailGeneratorRenderSettings Settings;
    Settings.OutputResolution = OutputResolution;
    Settings.GridWidth = GridWidth;
    Settings.GridHeight = GridHeight;
    Settings.FramePaddingPercent = FramePaddingPercent;
    Settings.FramingMode = FramingMode;
    Settings.FrameOffset = FrameOffset;
    Settings.bShowBounds = bShowBounds;
    Settings.bShowCheckerboard = bShowCheckerboard;
    Settings.bUsePreviewSceneSettings = bUsePreviewSceneSettings;
    Settings.bCaptureBloom = bCaptureBloom;
    Settings.bCaptureAntiAliasing = bCaptureAntiAliasing;
    Settings.bCaptureTemporalAA = bCaptureTemporalAA;
    Settings.bCaptureEveryFrame = bCaptureEveryFrame;
    Settings.bCaptureOnMovement = bCaptureOnMovement;
    Settings.bCaptureVignette = bCaptureVignette;
    Settings.bCaptureEyeAdaptation = bCaptureEyeAdaptation;
    Settings.bCapturePostProcessing = bCapturePostProcessing;
    Settings.bCaptureTonemapper = bCaptureTonemapper;
    Settings.bCaptureLighting = bCaptureLighting;
    Settings.bCaptureReflections = bCaptureReflections;
    Settings.bCaptureDeferredLighting = bCaptureDeferredLighting;
    Settings.bCaptureMaterials = bCaptureMaterials;
    Settings.bCaptureDepthOfField = bCaptureDepthOfField;
    Settings.ProjectionMode = ProjectionMode;
    Settings.CameraYaw = CameraYaw;
    Settings.CameraPitch = CameraPitch;
    Settings.PerspectiveFOV = PerspectiveFOV;
    Settings.DirectionalLightIntensity = DirectionalLightIntensity;
    Settings.DirectionalLightYaw = DirectionalLightYaw;
    Settings.DirectionalLightPitch = DirectionalLightPitch;
    Settings.SkyLightIntensity = SkyLightIntensity;
    Settings.bUseManualExposure = bUseManualExposure;
    Settings.ExposureCompensation = ExposureCompensation;
    return Settings;
}
