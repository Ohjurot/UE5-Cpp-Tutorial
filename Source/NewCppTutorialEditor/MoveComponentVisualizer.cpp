// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponentVisualizer.h"

void FMoveComponentVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
    // Get our move component
    const UMoveComponent* MoveComponent = Cast<UMoveComponent>(Component);
    if (MoveComponent)
    {
        PDI->DrawLine(
            MoveComponent->GetComponentLocation(),
            MoveComponent->GetComponentLocation() + MoveComponent->MoveOffset,
            FLinearColor::Red,
            SDPG_Foreground
        );
    }
}
